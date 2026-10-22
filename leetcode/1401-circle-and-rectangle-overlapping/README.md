<h2><a href="https://leetcode.com/problems/circle-and-rectangle-overlapping/">1401. Circle and Rectangle Overlapping</a></h2><h3>Medium</h3><hr><p>You are given a circle represented by its radius <code>radius</code> and center coordinates <code>(xCenter, yCenter)</code>. You are also given an axis-aligned rectangle represented by <code>(x1, y1, x2, y2)</code>, where <code>(x1, y1)</code> is the bottom-left corner and <code>(x2, y2)</code> is the top-right corner of the rectangle.</p>

<p>Return <code>true</code> if the circle and rectangle overlap; otherwise, return <code>false</code>.</p>

<p>Two shapes overlap if they share at least one point. Points on the boundaries are included, so touching at a single point also counts as overlapping.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/20/sample_4_1728.png" style="width: 258px; height: 167px;" />
<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The circle is centered at <code>(0, 0)</code> with radius <code>1</code>, and the rectangle extends from <code>(1, -1)</code> to <code>(3, 1)</code>.</li>
	<li>The circle and rectangle touch at the point <code>(1, 0)</code>, which lies on the circle&#39;s boundary and the rectangle&#39;s left edge.</li>
	<li>Since they share at least one point, they overlap. Therefore, return <code>true</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The circle is centered at <code>(1, 1)</code> with radius <code>1</code>, while the rectangle extends from <code>(1, -3)</code> to <code>(2, -1)</code>.</li>
	<li>The closest point on the rectangle to the circle&#39;s center is <code>(1, -1)</code>. The distance between these points is <code>2</code>, which is greater than the circle&#39;s radius of <code>1</code>.</li>
	<li>Since the circle cannot reach the rectangle, they do not overlap. Therefore, return <code>false</code>.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/02/20/sample_2_1728.png" style="width: 150px; height: 135px;" />
<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The circle is centered at <code>(0, 0)</code> with radius <code>1</code>, and the rectangle extends from <code>(-1, 0)</code> to <code>(0, 1)</code>.</li>
	<li>The point <code>(0, 0)</code> is both the center of the circle and the bottom-right corner of the rectangle.</li>
	<li>Since this point belongs to both shapes, they overlap. Therefore, return <code>true</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= radius &lt;= 2000</code></li>
	<li><code>-10<sup>4</sup> &lt;= xCenter, yCenter &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= x1 &lt; x2 &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= y1 &lt; y2 &lt;= 10<sup>4</sup></code></li>
</ul>
