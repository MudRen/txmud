// zz.c

inherit NPC;

void create()
{
	set_name("刘侠义", ({ "liu xia yi" }) );

	set("title", "「仁义庄主」");

        set("gender", "男性" );
        set("age", 56);
        set("long", "这是一位精神矍铄的老者，一脸
正气，不怒自威。\n");

	set("combat_exp", 5000);

	set("str", 30);

        setup();

	carry_object(__DIR__"obj/cloth")->wear();
}
