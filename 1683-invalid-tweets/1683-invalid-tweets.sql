# Write your MySQL query statement below

-- SELECT tweet_id FROM Tweets
-- WHERE (
--     SELECT content FROM Tweets
--     WHERE LENGTH(content) > 15
--     );

SELECT tweet_id FROM Tweets
WHERE LENGTH(content) > 15;