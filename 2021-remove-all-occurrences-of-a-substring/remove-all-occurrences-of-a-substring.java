class Solution {
    public static void removePart(StringBuilder s, String part, int i) {
        if(i > s.length()-part.length()) return;

        if(s.charAt(i) == part.charAt(0)) {
            // System.out.println("s sub: " + s.substring(i, i+part.length()));
            // System.out.println("part" + part);
            // System.out.println("sub: " + s.substring(i, i+part.length()).equals(part));
            if(s.substring(i, i+part.length()).toString().equals(part)) {    // required to convert StringBuilder into string because the default equals in StringBuilder compares the (reference equality) not the value.
                System.out.println("deleted from " + i + " to " + (i+part.length()));
                s.delete(i, i+part.length());
                i = -1;
            }
        }

        removePart(s, part, i+1);
    }
    public String removeOccurrences(String s, String part) {
        StringBuilder sb = new StringBuilder(s);
        removePart(sb, part, 0);
        return sb.toString();
    }
}