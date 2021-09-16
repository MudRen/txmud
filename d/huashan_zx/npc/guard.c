// guard.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("看门老人", ({ "old guard"}) );
	set("title", "门房");
	set("gender", "男性" );
	set("age", 76);
	set("str", 29);
	set("cor", 30);
	set("cps", 30);
	set("int", 11);
	set("long","这是一个满脸风霜的老人，除了岳不群
夫妇没有人知道他的出身来历。在华山
弟子们的眼里，他好像一直是这么老，
只偶而会笑一笑。\n");

	set("combat_exp", 2000);
	set("attitude", "friendly");
	set("chat_chance", 5);
	set("chat_msg", ({
		"看门老人道：想来是我老眼昏花了，他怎么可能是掌门？\n",
		"看门老人道：现在酒也越来越贵....呃....看来这点工钱还不够喝酒呢。\n",
		"看门老人道：想当年...唉...当年,,当年..当年...提它作甚。\n",
		"看门老人道：我这老寒腿呀，一到晚上就想喝两口....\n"
	}) );
	set("inquiry", ([
		"掌门": "岳先生还没回来，不过，唉，我可能看错了。不提也罢。",
		"酒":"酒可是好东西，一醉解千愁。",
		"name":"我？老了，都不记得了。（看来老人不太想告诉你。）",
		"风清杨":"呃，风清杨，在紫霞宫少提这个人吧，掌门不喜欢他。",
		"黄衣少女":"那个丫头不错，常给我酒喝。",
	]) );

	set_skill("blade", 40);
	set_skill("parry", 40);
	
	setup();
	
	carry_object(__DIR__"obj/cloth")->wear();
}
