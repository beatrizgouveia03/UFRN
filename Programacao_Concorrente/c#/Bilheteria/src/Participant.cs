namespace Bilheteria;

using System.Threading;

public class Participant(Ticket ticket)
{
    private readonly Ticket my_ticket = ticket;
    private int my_seat = -1;

    public void Run(){
        my_seat = my_ticket.GetTicket();

        if(my_seat == -1){
            Console.WriteLine(Thread.CurrentThread.Name + ": Não há mais ingressos.");
        } else {
            Console.WriteLine(Thread.CurrentThread.Name + ": Comprou assento. Restam " + my_ticket.GetAvailableTickets() + " ingressos.");
        }
    }
}