package imd.ufrn.br.bilheteria;

public class Main {

	public static void main(String[] args) throws InterruptedException {
		final int MAX_TICKETS = 10000;
		Ticket ticket = new Ticket(1, MAX_TICKETS);
		
		while(true) {
			//Thread t = new Participant(ticket);
			Runnable r = new Participant2(ticket);
			Thread t = new Thread(r);
			t.start();
		}
	}

}
