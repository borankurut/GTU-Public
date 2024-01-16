package homework1;

/**
 * Interaction is super class of like and comments. 
 * It contains the id of the interaction, id of interacted post, id of the account that interacted
 */

public abstract class Interaction{
    final protected int interactionId;
    final protected Account interactedAccount;
    final protected Post postInteracted;

    /**
     * super constructor of like and comment
     * 
     * @param newInteractionId          id of the interaction
     * @param newinteractedAccount      account that interacted.
     * @param newPostInteracted         post that is interacted by account.
     */
    public Interaction(int newInteractionId, Account newInteractedAccount, Post newPostInteracted){
        interactionId = newInteractionId;
        interactedAccount = newInteractedAccount;
        postInteracted = newPostInteracted;
    }

    /**
     * 
     * @return id of the interaction.
     */
    public int getId() {
        return interactionId;
    }

    @Override
    public String toString() {
        return String.format("Interaction Id: %s, Account Id: %s, Post Id: %s",
        interactionId, interactedAccount.getId(), postInteracted.getId());
    }

    public Account getAccount(){return interactedAccount;}

    public Post getPost(){return postInteracted;}
    
    /**
     * interact is an abstract function 
     * that is going to be implemented by the like and comment classes separately.
     * 
     * @param interacted post that is interacted.
     */
    public abstract void interact(Post interacted);

}