package imd.ufrn.br.bilheteria;

public class Participant extends Thread {
	Ticket myticket;
	private int myseat;
	
	public Participant(Ticket ticket) {
		super();
		myticket = ticket;
		myseat = -1;
	}
	
	public void run() {
		myseat = myticket.getTicket();
		
		if(myseat == -1) {
			System.out.println(Thread.currentThread().getName() + ": Não há mais ingressos");
		} else {
			System.out.println(Thread.currentThread().getName() + ": Comprou assento. Restam" + myticket.getAvailableTickets() + " ingressos.");
		}
	}
}
