//老土狼练习专用npc
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("微酸妙儿", ({ "miao er", "miao", "me" }));
        set("title",HIW"漂亮MM"NOR);
        set("age", 20);
        set("gender", "女性");

        set("long",
            "她就是老土狼的书童。
每天只有她一个人在这里培着寂寞的老土狼。\n" );
        set("str", 20); 
        set("int", 30); 
        set("con", 30);
        set("dex", 30);
        set("per", 100);
       
        set("force", 9999);
        set("max_force", 9999);
        set("combat_exp", 25000000);
        set("force_factor", 2);

        set_skill("unarmed",300);
        set_skill("dodge",300);
        set_skill("force", 300);
        set_skill("parry", 310);
         set("inquiry" ,([
         "zling":"微酸妙儿嫣然一笑：“那是我的主人，你见过他了吗？如果他没有在这里，肯定在玩COMMANDOS2”\n",
         "老土狼":"微酸妙儿嫣然一笑：“那是我的主人，你见过他了吗？如果他没有在这里，肯定在玩COMMANDOS2”\n",
"电话号码":"他的电话号码是13920733840，嘘，不要告诉别人呀”\n",
          ]));
         add_money("gold",4000);
         carry_object(ARMOR_DIR"cloth")->wear();

setup();
  }
