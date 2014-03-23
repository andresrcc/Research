
public class calc{
    private int a,b;
    private String op;

    public calc(int left, String operation, int right){
	a = left;
	op = operation;
	b = right;
    }

    public void printValues(){
	System.out.print(a);
	System.out.print(op);
	System.out.print(b);
	System.out.println("");
    }

    public static void main(String[] args){
	calc calculator = new calc(Integer.parseInt(args[0]), args[1], Integer.parseInt(args[2]));
	calculator.printValues();
    }


}
