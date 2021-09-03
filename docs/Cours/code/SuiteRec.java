/* exemple en java */
/** suite recurrente
u_{n+1} = a*u_n+b
*/
class SuiteRec {
    private double a, b, u0;

    public SuiteRec(int a, int b, int u0){
        this.a = a;
        this.b = b;
        this.u0 = u0;
    }

    public double nieme(int n){
        double u = u0;
        for(int i=0; i<n; i++)
            u = a*u + b;
        return u;
    }

    public static void main(String[] args){
        SuiteRec suite = new SuiteRec(2, 1, 1);
        double u5 = suite.nieme(5),
            u10 = suite.nieme(10);
        System.out.print(u10);
    }
}
