// gunu.c 
// dicky.c


#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("孤女", ({ "gu nv", "girl"}));
	set("nickname", HIG"天涯孤女"NOR);
	set("long", 
"孤女固执地守在客栈外，眼睛死死的盯着客栈里面正在吃喝的人群。\n"
"每个人都会坚持自己的信念，在别人看来，是浪费时间，她却觉得很重要。\n");
	set("gender", "女性");
	set("age", 28);
	set("title", HIB"靖海遗孤"NOR);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);	
        set("per", 21);

        set("combat_exp", 800000);
        set("max_kee",2000);
        set("max_gin",2000);
        set("max_sen",2000);

        set("force", 4500);
        set("max_force", 4500);
        set("atman", 2500);
        set("max_atman", 2500);
        set("mana", 2500);
        set("max_mana", 2500);
        set("force_factor", 150);

        set_skill("jinghai-force",110);
        set_skill("longjiao-blade",100);
        set_skill("blade",120);
        set_skill("unarmed",120);                     
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("force",120);
        set_skill("sword",120);
        set_skill("bibo-sword",100);
        set_skill("perception",100);
        set_skill("xian-steps",120);
        set_skill("canhe-zhi",120);

        map_skill("unarmed","canhe-zhi");
        map_skill("force","jinghai-force");
        map_skill("dodge","xian-steps");
        map_skill("parry","bibo-sword");
        map_skill("sword","bibo-sword");

	set("chat_chance", 1);
	set("chat_msg", ({
		"孤女恨恨的说道:为了了却百般莫解的仇怨，我宁愿在这里等一辈子。\n",
	}) );
	set("inquiry", ([
		"理由" : "杀一人需要理由么？等你爱上一个人，你就能体会这道理！\n",
		"拒绝" : "从小我就懂得保护自己，我知道要想不被人拒绝，最好的办法就是先拒绝别人。\n",
		"分离" : "我曾经听人说过，当你不能够再拥有的时候，你唯一可以做的就是令自己不要忘记。\n",
		"爱情" : "你最爱的女人是不是我？但是我现在已经不想知道。如果有一天我忍不住问你，你一定要骗我。就算你心里多不情愿，也不要告诉我你最爱的人不是我。\n",
	]));

        setup();

        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(WEAPON_DIR"sword")->wield();
}


