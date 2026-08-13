# contributing

Thank you for considering a contribution.

Flatman is an open source TUI for managing flatpak applications.

The project is developed collaboratively, and contributions of all sizes are welcome.

## Before starting

Before working on a change please first:
1. Check the existing issues and TODO.md
2. Check whether someone is already working on the same thing
3. For large or potentially disruptive changes, open an issue or discussion first.
4. For small fixes and improvements, you can generally begin work without opening an issue first.

All of these points are intended to prevent multiple contributors from independently working 
on the same feature.

### Tasks without an issue

Small changes do not require an issue.

If a task is not associated with an issue and you want to work on it, you can create an issue
if you theorise that coordination or discussion would be useful.

### Adding New work 

If you want to work on something that is not currently listed in 'TODO.md', create
an issue describing the proposed change before starting substantial work.

After the change has been agreed upon, the TODO list can be updated if the work is part
of the project's planned development.

### Keeping Tasks Updated

Contributors should update the relevant issue when circumstances change.

For example, If:
- You stop working on a task.
- You discover that the proposed approach will not work.
- The scope of the task changes significantly.
- You need help from another contributor.
- The task is blocked by another issue.

This allows other contributors to see the current state of the work before starting
something themselves.


## workflow
1. Create branch for your change.
2. Make your changes
3. Test
4. Commit changes.
5. Push branch
6. Open a pull request.

## Branches
Use a branch name that gives a good idea of what you're working on.

Examples:
feature/application-search
feature/application-details
fix/search-crash
fix/terminal-cleanup
docs/contributing

Avoid using main directly for feature dev

## Commits

Commits should describe a single logical change (whether it be big or small).

Examples:
Add flatpak search
Add application details view
Fix terminal cleanup on exit
Update contribution guidelines

Avoid combining unrelated changes into a single commit (albeit it's not the end of the world if you do, just make sure to make it clear in the commit message what you're changing).

## Testing
Before opening a PR, make sure the project builds okay and test functionality affected by your changes

At minimum: 

```
make
./flatman
```

New functionality should be tested manually where appropriate. Please avoid introducing compiler warnings.

## PRs

PRs should:
- Clearly describe what has changed.
- Explain how changes were tested.
- Reference the relevant issue when applicable
- Contain only changes relevant to the proposed change.
- Be ready for review before requesting a merge

If these rules seem gruelling, just keep PRs reasonably focused. Large changes should generally be discussed before implementation.

## Code Quality
Contributors should aim to keep code:
- Readable
- Maintainable
- Consistent with the existing project
- Properly separated into appropriate comments
- Free of unnecessary complexity.

If a change introduces a significant architectural decision, discuss it with other contributors before implementation where practical.

## Updating TODO.md
```TODO.md``` represents planned and outstanding work.

Contributors should update it when completing a planned task or when the project's plans
change significantly.

Do not add every small idea or potential improvement to ```TODO.md```. Issues are better suited for ideas, bugs, and work that has not yet been accepted as planned development.

## Questions and Discussion
If you are unsure whether a change should be discussed before implementation, open an issue or discussion rather than duplicating existing work or making a potentially disruptive change without coordination.


