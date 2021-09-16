//qiaofu.c

inherit NPC;

void create()
{
	set_name("樵夫", ({ "wood cutter" }) );

	set("gender", "男性" );

	set("age", 26);

	set("long", "这是一位穿著粗布衣服的粗壮的大汉。\n");

	set("combat_exp", 2000);

	set("str", 30);

	set("chat_chance", 3);
	set("chat_msg", ({
		"樵夫自语道：真是怪，我明明看见有人跳进山涧里的...\n",
		"樵夫叹道：好好的人，干嘛要寻死呢。\n",
		"樵夫叹道：听说老王家把二小子送到西道观净了身，要进宫当太监。\n",
		"樵夫叹道：老王家好在有两个儿子，不会断了香火。\n",
		"樵夫叹道：毛女洞里听说有妖精，吃人咧。\n",
		"樵夫叹道：华山派的人请了个疯疯颠颠的人在造剑咧。\n",
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
