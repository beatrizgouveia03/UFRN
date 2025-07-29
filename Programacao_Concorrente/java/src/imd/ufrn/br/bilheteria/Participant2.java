package imd.ufrn.br.bilheteria;

public class Participant2 implements Runnable {
	Ticket myticket;
	private int myseat;
	
	public Participant2(Ticket ticket) {
		myticket = ticket;
		myseat = -1;
	}

	@Override
	public void run() {
		myseat = myticket.getTicket();
		
		if(myseat == -1) {
			System.out.println(Thread.currentThread().getName() + ": Não há mais ingressos");
		} else {
			System.out.println(Thread.currentThread().getName() + ": Comprou assento. Restam " + myticket.getAvailableTickets() + " ingressos.");
		}

	}

}
