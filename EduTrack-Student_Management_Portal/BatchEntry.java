package com.marvellous.MarvellousFullStack.Entity;

import lombok.Getter;
import lombok.Setter;
import org.bson.types.ObjectId;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document(collection = "BatchDetails")
@Getter
@Setter
public class BatchEntry
{
    @Id
    private ObjectId id;
    private String name;
    private int fees;



    public void setName(String name) {
        this.name = name;
    }

  public String getName() {

      return name;
  }
  public int getFees()
  {
      return fees;
  }

    public void setFees(int fees) {
        this.fees = fees;
    }

    public void setId(ObjectId id) {
    }
}
