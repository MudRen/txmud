// stdnpc_6.c

inherit STD_NPC;
 
void create()
{
	set_name("蒙面人", ({ "mengmian ren","ren","mengmian"}) );
	set("long", "这是一位莫名其妙的家伙,戴着面具,看不清他的真面目。\n");
	set("gender","男性");

	set("age",32);

	set_npc_level(10);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
