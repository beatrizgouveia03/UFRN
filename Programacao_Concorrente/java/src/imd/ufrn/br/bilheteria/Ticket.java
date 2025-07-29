package imd.ufrn.br.bilheteria;

public class Ticket {
	private int value;
	private final int maxTickets;
	private int soldTickets;
	
	public Ticket(int n, int max) {
		value = n;
		maxTickets = max;
		soldTickets = 0;
	}
	
	public int getTicket()
	{
		if(soldTickets >= maxTickets) { return -1;}
		soldTickets++;
		return value++;
	}
	
	public int getAvailableTickets() {
		return maxTickets - soldTickets;
	}
}
