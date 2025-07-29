namespace Bilheteria;

public class Ticket(int n, int max)
{
    private int value = n;
    private readonly int max_tickets = max;
    private int sold_tickets = 0;

    public int GetTicket(){
        if(sold_tickets > max_tickets){
            return -1;
        }
        
        sold_tickets++;
        return value++;
    }

    public int GetAvailableTickets(){
        return max_tickets-sold_tickets;
    }
}