// thief.c
inherit NPC;
 
void create()
{
        set_name("黑衣老人", ({ "oldman" }) );
        set("rank", "盗贼");
        set("gender", "男性" );
        set("age", 65);
        set("int", 25);
        set("con", 28);
        set("long", @LONG
一个身穿黑衣的老人，虽然年纪很大了，却脸色红润，眼睛炯炯有神。
LONG
);
        set("combat_exp", 3000);
        set("attitude", "heroism");
        set("env/wimpy", 70);
        set_skill("sword", 140);
        set_skill("parry", 150);
        set_skill("dodge", 200);
        set_skill("dagger", 125);
        set_skill("stealing",135); 
        setup();
 
        add_money("gold",1);
        //carry_object("/u/cloud/obj/cloth/black_cloth")->wear();
        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(WEAPON_DIR"sword")->wield();
        
        set("score",-30);
}
