package com.marvellous.MarvellousFullStack.Service;

import com.marvellous.MarvellousFullStack.Entity.BatchEntry;
import com.marvellous.MarvellousFullStack.Repository.BatchEntryRepository;
import org.bson.types.ObjectId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.List;
import java.util.Optional;

@Component
public class BatchEntryService
{
    @Autowired
    private BatchEntryRepository batchEntryRepository;

    // C : Create POST
    public BatchEntry saveEntry(BatchEntry batchEntry)
    {
        return batchEntryRepository.save(batchEntry);
    }

    // R : Read GET
    public List<BatchEntry> getALl()
    {
        return batchEntryRepository.findAll();
    }

    // U : Update PUT
    public Optional<BatchEntry> findById(ObjectId id)
    {
        return batchEntryRepository.findById(id);
    }

    // D : Delete DELETE
    public void deleteById(ObjectId id)
    {
        batchEntryRepository.deleteById(id);
    }

    public BatchEntry updateById(ObjectId id,BatchEntry updated)
    {
        updated.setId(id);
        return batchEntryRepository.save(updated);
    }


}
