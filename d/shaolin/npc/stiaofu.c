// stiaofu.c

inherit NPC;

void create()
{
	set_name("山挑夫", ({ "tiao fu", "porter" }) );
	set("gender", "男性" );
	set("age", 20+random(15));
	set("long","这是个老实巴交的穷挑夫，可能是由于
经常爬山，两腿肌肉非常发达。\n");
	set("combat_exp", 10000+random(5000));

	set_skill("dodge",60);
	set_skill("unarmed",40);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}