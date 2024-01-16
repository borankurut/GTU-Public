package homework1;

/**
 * Message class contains information of message id, sender account id, receiver account id, 
 * content of the message.
 */

public class Message{

    private final int messageId;
    private final int senderId;
    private final int receiverId;
    private final String content;


    /**
     * Creates new message object with id, sender, receiver and content information.
     * 
     * @param newMessageId      id of the message object.
     * @param newSenderID       id of the sender account.
     * @param newReceiverId     id of the receiver account.
     * @param newContent        content of the message.
     */
    public Message(int newMessageId, int newSenderID, int newReceiverId, String newContent){
        messageId = newMessageId;
        senderId = newSenderID;
        receiverId = newReceiverId;
        content = newContent;
    }

    /**
     * 
     * @return  id of the message object.
     */
    public int getId() {return messageId;}

    /**
     * 
     * @return  id of the sender account.
     */
    public int getSenderId(){return senderId;}

    /**
     * 
     * @return  id of the receiver account.
     */
    public int getReceiverId(){return receiverId;}

    /**
     * 
     * @return  content of the message.
     */
    public String getContent(){return content;}

    @Override
    public String toString(){
        return String.format("MessageId: %s, SenderId: %s, ReceiverId: %s, Content:%s",
            messageId, senderId, receiverId, content);
    }
}