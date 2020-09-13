use std::collections::HashMap;
pub struct Solution{}
impl Solution {
    pub fn can_finish(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> bool {
        let mut graph: HashMap<i32, Vec<i32>> = HashMap::new();
        let access = vec![false; num_courses as usize];

        for courses in prerequisites.iter() {
            let (course1, course2) = (courses[0], courses[1]);
            if Solution::dfs(&graph, course1, course2, access.clone().as_mut()) == true {
                return false;
            }

            if graph.contains_key(&course2) {
                if let Some(tmp) = graph.get_mut(&course2) {
                    (*tmp).push(course1);
                }
            } else {
                graph.insert(course2, vec![course1]);
            }
        }
        true
    }

    fn dfs(graph: &HashMap<i32, Vec<i32>>, course1: i32, course2: i32, access: &mut Vec<bool>) -> bool {
        if course1 == course2  {
            return true;
        }

        for elem_vec in graph.get(&course1) {
            for elem in elem_vec {
                if Solution::dfs(graph, *elem, course2, access) == true {
                    return true;
                }
            }

        }
        false
    }
}