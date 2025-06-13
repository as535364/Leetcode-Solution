<h2><a href="https://leetcode.com/problems/zero-array-transformation-ii">3356. Zero Array Transformation II</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>nums</code> of length <code>n</code> and a 2D array <code>queries</code> where <code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>, val<sub>i</sub>]</code>.</p>

<p>Each <code>queries[i]</code> represents the following action on <code>nums</code>:</p>

<ul>
	<li>Decrement the value at each index in the range <code>[l<sub>i</sub>, r<sub>i</sub>]</code> in <code>nums</code> by <strong>at most</strong> <code>val<sub>i</sub></code>.</li>
	<li>The amount by which each value is decremented<!-- notionvc: b232c9d9-a32d-448c-85b8-b637de593c11 --> can be chosen <strong>independently</strong> for each index.</li>
</ul>

<p>A <strong>Zero Array</strong> is an array with all its elements equal to 0.</p>

<p>Return the <strong>minimum</strong> possible <strong>non-negative</strong> value of <code>k</code>, such that after processing the first <code>k</code> queries in <strong>sequence</strong>, <code>nums</code> becomes a <strong>Zero Array</strong>. If no such <code>k</code> exists, return -1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><strong>For i = 0 (l = 0, r = 2, val = 1):</strong>

	<ul>
		<li>Decrement values at indices <code>[0, 1, 2]</code> by <code>[1, 0, 1]</code> respectively.</li>
		<li>The array will become <code>[1, 0, 1]</code>.</li>
	</ul>
	</li>
	<li><strong>For i = 1 (l = 0, r = 2, val = 1):</strong>
	<ul>
		<li>Decrement values at indices <code>[0, 1, 2]</code> by <code>[1, 0, 1]</code> respectively.</li>
		<li>The array will become <code>[0, 0, 0]</code>, which is a Zero Array. Therefore, the minimum value of <code>k</code> is 2.</li>
	</ul>
	</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li><strong>For i = 0 (l = 1, r = 3, val = 2):</strong>

	<ul>
		<li>Decrement values at indices <code>[1, 2, 3]</code> by <code>[2, 2, 1]</code> respectively.</li>
		<li>The array will become <code>[4, 1, 0, 0]</code>.</li>
	</ul>
	</li>
	<li><strong>For i = 1 (l = 0, r = 2, val<span style="font-size: 13.3333px;"> </span>= 1):</strong>
	<ul>
		<li>Decrement values at indices <code>[0, 1, 2]</code> by <code>[1, 1, 0]</code> respectively.</li>
		<li>The array will become <code>[3, 0, 0, 0]</code>, which is not a Zero Array.</li>
	</ul>
	</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 3</code></li>
	<li><code>0 &lt;= l<sub>i</sub> &lt;= r<sub>i</sub> &lt; nums.length</code></li>
	<li><code>1 &lt;= val<sub>i</sub> &lt;= 5</code></li>
</ul>
