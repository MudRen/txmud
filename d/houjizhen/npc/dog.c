// dog.c
// by dicky

inherit NPC;

void create()
{
        set_name("看门狗", ({ "kanmen dog","dog" }) );
        set("race", "野兽");
        set("age", 3);
	set("long", "这是一只看门狗，饿得只剩下皮包骨头。\n");
        set("attitude", "heroism");

        set("max_kee", 500);
        set("max_gin", 500);
        set("max_sen", 500);
        
        set("combat_exp", 50000);
        set("limbs", ({ "头部", "身体", "尾巴","前脚", "後脚"}) );
        set("verbs", ({ "bite","claw" }) );
        set("str",20);
        set("cor",30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "看家狗用一种悲伤的眼光看着你,为这世界的不公感道无可奈何!\n",
         }));

	set_temp("apply/attack", 35);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 20);
        setup();
}
