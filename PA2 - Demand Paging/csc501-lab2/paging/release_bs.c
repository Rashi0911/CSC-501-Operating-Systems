#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <paging.h>

SYSCALL release_bs(bsd_t bs_id) {

  	/* release the backing store with ID bs_id */
	bsm_tab[bs_id].bs_status = BSM_UNMAPPED;
	bsm_tab[bs_id].bs_pid = -1;
	bsm_tab[bs_id].bs_vpno = VPN_BASE;
	bsm_tab[bs_id].bs_npages = 0;
	bsm_tab[bs_id].bs_sem = 0;
	bsm_tab[bs_id].bs_priv_heap = 0;
	
	free_bsm(bs_id);
	return(OK);
}

