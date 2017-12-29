/**
 * Created by William Tennis on 4/4/16.
 */
 
public class Score <T>{
    private String name;
    private T score;

    public Score(String name, T score) {
        this.name = name;
        this.score = score;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public T getScore() {
        return score;
    }

    public void setScore(T score) {
        this.score = score;
    }

    public String toString() {
        
        return "Name: " + name + "\tScore: " + score;
    }
}
