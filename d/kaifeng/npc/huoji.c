inherit NPC;

void create()
{
        set_name("伙计", ({ "huo ji" }) );
        set("gender", "男性" );
        set("age", 19);
        set("long", "一个年纪轻轻的伙计.\n");

        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("parry", 10);
        set_skill("dodge", 10);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
