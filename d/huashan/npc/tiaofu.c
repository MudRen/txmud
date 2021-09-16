//tiaoshan.c

inherit NPC;

void create()
{
	set_name("挑夫", ({ "tiao fu" }) );

	set("gender", "男性" );

	set("age", 26);
	set("long", "一个粗壮的大汉，身上穿著粗布衣服。
肩上担着一担货物。\n");

	set("combat_exp", 2000);
	set("str", 30);
	set("chat_chance", 3);

	set("chat_msg", ({
		"挑夫自语道：苦命呀...，挑一天也吃不上两顿饱饭。\n",
		"樵夫叹道：这两年天下不太平，来游山的人也少了许多。\n",
		(: random_move :),
}) );
	set("env/wimpy", 10);

	set("inquiry", ([
		"华山":"华山？这周围近百里都是华山。",
		"华山派" : "你找找吧，不远了。",
		"风清杨":"风老先生？听说过，不过哪是我这种人能见的到的呢？",
		"here": "这里便是华山。",
]) );

        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}
