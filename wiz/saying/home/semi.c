//无聊说者的偶像
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("三米",({"semi","mylove"}));
       set("title",HIR"红色天使"NOR);
        set("age",19);
        set("gender", "女性");
        set(NO_KILL,1);

        set("long",@long
    据说天界有九种天使，然而谁也不知道第十种天使的存在。
无论是堕天使、炽天使，还是所谓的六翼天使，都没有这一个神
秘，也没有这一个美丽。她只生活在纯真的爱情中，为了梦想她
逃离了天堂。无聊说者某天看到了她的背影，于是偷偷按照自己
的回忆在这里留下了她的影子。
long
       );
        set("str", 20); 
        set("int", 30); 
        set("con", 30);
        set("dex", 30);
        set("per", 100);
        add_temp("apply/unarmed", 900);
        add_temp("apply/armor", 900);
        add_temp("apply/damage", 900);
        add_temp("apply/parry", 900);
        add_temp("apply/dodge", 900);
       
        set("kee",10000);
        set("max_kee",10000);
        set("gin",10000);
        set("max_gin",10000);
        set("sen",10000);
        set("max_sen",10000);
        set("combat_exp",100000000);

         set("inquiry" ,([
        "天堂":"天堂？有爱的地方就是天堂......",
        "爱情":"为了爱情，我愿意折断自己的翅膀",
        "天使":"有一种纯洁的生物，人们把它们叫做天使。",
        "无聊说者":"无聊说者是谁？我不认识.....",
        "工作":"什么工作？是那个混蛋saying的工作吗？给他出点主意吧！",
        "all":"你可以问我有关「工作」的事情，还有些其他的问题，就靠你自己发掘啦。",
          ]));
           setup();
        carry_object("/d/feiyu/npc/obj/nishang.c")->wear();
        carry_object("/d/feiyu/obj/hflower.c")->wear();

}
