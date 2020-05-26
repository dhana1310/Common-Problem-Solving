import lombok.Data;

import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Main {

    public static void main(String[] args) {

        String json = "{\"id\":1,\"name\":\"Dhananjay\",\"address\":{\"street\":{\"buildingsList\":[{\"buildingName\":\"Sneha Vihar\",\"floors\":8},{\"buildingName\":\"River view\",\"floors\":4}],\"address2\":\"NDA Road\"},\"landmark\":\"Shinde Pool\"}}";
        Map<String, Object> flattenJson = JsonFlattener.flattenAsMap(json);
        String input = "." + "buildingName";

        System.out.println(populatePaths(flattenJson, input, new Person()));
    }

    private static <T> Set<String> populatePaths(Map<String, Object> flattenJson, String input, T t) {
        Set<String> set = new HashSet<>();
        flattenJson.forEach((k, v) -> {
            if (k.endsWith(input)) {
                String out = k.replaceAll("\\[\\d\\]", "[]");
                set.add(t.getClass().getName() + "." + out);
            }
        });
        return set;
    }
}

/*<dependency>
    <groupId>com.github.wnameless.json</groupId>
    <artifactId>json-flattener</artifactId>
    <version>0.8.1</version>
</dependency>*/


@Data
class Person {
    private Integer id = 1;
    private String name;
    private Address address;
}

@Data
class Address {
    private Street street;
    private String landmark;
}

@Data
class Street {
    private List<Buildings> buildingsList;
    private String address2;
}

@Data
class Buildings {
    private String buildingName;
    private int floors;
}


