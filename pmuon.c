#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("YOUR NAME"); //write your name
MODULE_DESCRIPTION("PMUON");

void set_pmu(void* dummy) {
    uint64_t v;
    printk("Turn PMU on Core %d\n", smp_processor_id());

    // 1. Enable "User Enable Register"
    asm volatile("msr pmuserenr_el0, %0" :: "r" (0x00000001)); 

    // 2. Reset i) Performance Monitor Control Register(PMCR),
    // ii) Count Enable Set Register, and
    // iii) Overflow Flag Status Register
    asm volatile ("msr pmcr_el0, %0" :: "r" (0x00000017));
    asm volatile ("msr pmcntenset_el0, %0" :: "r" (0x8000003f));
    asm volatile ("msr pmovsclr_el0, %0" :: "r" (0x8000003f));

    // 3. Disable Interrupt Enable Clear Register
    asm volatile("msr pmintenclr_el1, %0" :: "r" (~0));

    // 4. Read how many event counters exist 
    asm volatile("mrs %0, pmcr_el0" : "=r" (v)); // Read PMCR
    printk("We have %llu configurable event counters on Core %d\n",
            (v >> 11) & 0x1F, smp_processor_id());

    // 5. Set event counter registers (Assignment you need to IMPLEMENT)

}

void stop_pmu(void* dummy) {
    // 6. Read and disable event counter registers (Assignment you need to IMPLEMENT)
}



int init_module(void) {
    // Set Performance Monitoring Unit (aka Performance Counter) across all cores 
    on_each_cpu(set_pmu, NULL, 1);
    printk("Ready to use PMU\n");
    return 0;
}
    
void cleanup_module(void) {
    printk("PMU Kernel Module Off\n");
    on_each_cpu(stop_pmu, NULL, 1);
}

