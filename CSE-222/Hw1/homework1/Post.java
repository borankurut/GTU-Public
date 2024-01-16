package homework1;

/**
 * Contains information about the post shared by an account.
 * id, id of the account shared the post, likes, comments and content of the post.
 */

public class Post{
    private final int postId;

    private final int accountId;

    private Like likes[];
    private int likesSize;

    private Comment comments[];
    private int commentsSize;

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

        likes = new Like[10];
        comments = new Comment[10];

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
        likes[likesSize++] = l;
    }

    /**
     * 
     * @return  likes array.
     */
    public Like[] getLike(){return likes;}

    public int getLikeCount(){return likesSize;}

    public int getCommentCount(){return commentsSize;}

    /**
     * adds com to the comments array.
     * @param com   comment to be added to the post.
     */
    public void addComment(Comment com){
        comments[commentsSize++] = com;
    }

    /**
     * 
     * @return comments array.
     */
    public Comment[] getComments(){return comments;}
}