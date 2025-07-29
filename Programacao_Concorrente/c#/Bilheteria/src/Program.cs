namespace Bilheteria;

class Program{
    static void Main(string[] args){
        const int MAX_TICKETS = 100000;
        Ticket ticket = new(1, MAX_TICKETS);

        while(true){
            Participant p = new(ticket);
            Thread t = new(p.Run);
            t.Start();                
        }
    }
}
