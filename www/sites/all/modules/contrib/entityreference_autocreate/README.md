# Entity Reference Autocreate

A deliberately simple way to invent nodes on the fly in order to refer to them
via entityreference.

## Usage

This is a widget _enhancement_, not even a new widget.
It extends beyond entityreference autocomplete to create nodes in the same way
that taxonomy freetagging creates tags.

Just type a title into an entityreference autocomplete field, and if no match is
found, a placeholder of that name will be created silently, instead of 
complaining.

Great for rapdly and intuatively building out a network of linked items.

## Details

Full arbitrary entity support has been added (!) so this will also work on
users, taxonomy terms (though that functionality already exists) AND
whatever else entity API supports. In theory at least.

Created user accounts will NOT be enabled by default however, so they will
start off blocked. This is for security while we review for possible issues.
Let me know if there is even any reason to support this, it's there only because
users are entities too.

This feature will not work if your entityreference field can refer to more than
one bundle! In such a case we can't even guess what you want to create.
If you need to choose bundle types as you go, you are better off
with references_dialog.module or inline_entity_form.module

## Configuration

Configuration is on the field management page for the entityreference field.

Options exist for selecting the assigned user and the publish state of nodes
(only) on creation.
However further settings will not be supported there.

Roadmap is to maybe allow the admin to select a template entity
that will be cloned and re-labelled to serve as a placeholder if needed.

## Compare with

* **references_dialog.module**
RECOMMENDED. You can use this as well to create referred nodes on the fly.
The only reason it's not the entire solution is because you have to choose 
to do so each time.
Use references_dialog AS WELL AS this module for the best mix.

* **inline_entity_form.module**
RECOMMENDED. Nests a whole edit form inside your current one for each referred
entity though, so it gets clunky with complex or multiple items.

* **autocreate.module**
DO NOT USE. Not sure what happened with the D7 branch, but it decided to make 
its own field type instead of building on entityreference. Incompatible.
However, it did have the innovation of declaring a 'template' not to be used 
when autocreating a target. Good idea. UI is weird though. Cannot use.

* **noderefcreate.module**
Runner-up to references_dialog. However only supports nodereference at this 
time.

* **entityconnect.module**
A contender for generic reference create and edit. May work.
However button layouts it added to the UI were inconsistent under vertical tabs.
Caused visits to new form pages when creating new items. 
This was the main reason references_dialog won.
