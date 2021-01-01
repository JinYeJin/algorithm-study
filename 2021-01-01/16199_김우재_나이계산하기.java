import java.util.*;
import java.time.LocalDate;

public class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        LocalDate birth = LocalDate.of(scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
        LocalDate now = LocalDate.of(scanner.nextInt(), scanner.nextInt(), scanner.nextInt());

        long birth_year = birth.getYear();
        long now_year = now.getYear();

        long korean_old = (now_year - birth_year +1);
        long year_old = (now_year - birth_year);
        long man_old = year_old;

        if(man_old != 0 && birth.plusYears(man_old).isAfter(now)){
            man_old = man_old -1;
        }

        System.out.println(man_old);
        System.out.println(korean_old);
        System.out.println(year_old);

    }
}
 
