package refact;

import java.util.ArrayList;

import org.apache.ibatis.annotations.Select;

public interface MyMapper {

    @Select("SELECT word from words")
    public ArrayList<String> getWords();
}