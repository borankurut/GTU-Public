package homework1;

/**
 * Like class that contain information of account that liked the post and the post that is liked.
 */

public class Like extends Interaction{
    /**
     * @param newLikeId     Id of the like.
     * @param newAccount    account that liked the post.
     * @param newPost       The liked post
     */
    Like(int newLikeId, Account newAccount, Post newPost){
        super(newLikeId, newAccount, newPost);
    }

    /**
     * Adds this like to the post likes.
     * @interacted post that is liked
     */
    @Override
    public void interact(Post interacted) {
        interacted.addLike(this);
    }

    /**
     * Prints like information.
     */
    @Override
    public String toString() {
        return "Like: " + super.toString();
    }
}