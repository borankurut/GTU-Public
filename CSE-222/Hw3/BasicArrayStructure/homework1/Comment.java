package homework1;

/**
 * Comment contains information of the comment of the posts.
 * id, id of the account commented, post that is commented, content of the comment.
 */

class Comment extends Interaction{
    
    private String content; // content of the comment.

    /**
     * Creates new comment object
     * @param newCommentId      id of the comment object.
     * @param newAccount        account that commented.
     * @param newPost           post which is commented by account.
     * @param newContent        content of the comment.
     */
    public Comment(int newCommentId, Account newAccount, Post newPost, String newContent){
        super(newCommentId, newAccount, newPost);
        content = newContent;
    }

    @Override
    public String toString() {
        return String.format("Comment %s: '%s' said '%s'", 
        getId(), interactedAccount.getUsername(), content);
    }

    /**
     * comment interaction is simply adding this comment to the comments array of the post.
     */
    @Override
    public void interact(Post interacted) {
        interacted.addComment(this);
    }
}