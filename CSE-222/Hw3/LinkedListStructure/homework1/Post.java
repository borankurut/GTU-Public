package homework1;

import java.util.LinkedList;

/**
 * Contains information about the post shared by an account.
 * id, id of the account shared the post, likes, comments and content of the post.
 */

public class Post{
    private final int postId;

    private final int accountId;

    private LinkedList<Like> likes;

    private LinkedList<Comment> comments;

    private String content;


    /**
     * Creates new post object 
     * 
     * @param newPostId         id of the new post object.
     * @param newAccountId      id of the account that shared the post.
     * @param newContent        content of the post.
     */
    public Post(int newPostId, int newAccountId, String newContent){
        postId = newPostId;
        accountId = newAccountId;

        likes = new LinkedList<Like>();
        comments = new LinkedList<Comment>();

        content = newContent;
    }


    /**
     * 
     * @return id of the post.
     */
    public int getId() {return postId;}

    @Override
    public String toString(){ 
        return String.format("Post Id: %s, Account Id: %s, Likes: %s," +
        "Comments: %s, Content: %s",
        postId, accountId, likes, comments, content);
    }

    /**
     * 
     * @return  content of the post.
     */
    public String getContent(){
        return content;
    }

    public int getAccountId(){return accountId;}

    /**
     * adds l to the likes array.
     * 
     * @param l like object to be added to the post.
     */
    public void addLike(Like l){
        likes.add(l);
    }

    /**
     * removes l from the likes array.
     * 
     * @param l like object to be removed from the post.
     */
    public void removeLike(Like l){
        likes.remove(l);
    }

    /**
     * 
     * @return  likes array.
     */
    public LinkedList<Like> getLike(){return likes;}

    public int getLikeCount(){return likes.size();}

    public int getCommentCount(){return comments.size();}

    /**
     * adds com to the comments array.
     * @param com   comment to be added to the post.
     */
    public void addComment(Comment com){
        comments.add(com);
    }

    /**
     * removes com from the comments array.
     * @param com   comment to be removed from the post.
     */
    public void removeComment(Comment com){
        comments.remove(com);
    }

    /**
     * 
     * @return comments array.
     */
    public LinkedList<Comment> getComments(){return comments;}
}