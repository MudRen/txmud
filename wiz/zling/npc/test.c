//��������ϰר��npc
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("΢�����", ({ "miao er", "miao", "me" }));
        set("title",HIW"Ư��MM"NOR);
        set("age", 20);
        set("gender", "Ů��");

        set("long",
            "�����������ǵ���ͯ��
ÿ��ֻ����һ�������������ż�į�������ǡ�\n" );
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
         "zling":"΢�������ȻһЦ���������ҵ����ˣ�����������������û��������϶�����COMMANDOS2��\n",
         "������":"΢�������ȻһЦ���������ҵ����ˣ�����������������û��������϶�����COMMANDOS2��\n",
"�绰����":"���ĵ绰������13920733840���꣬��Ҫ���߱���ѽ��\n",
          ]));
         add_money("gold",4000);
         carry_object(ARMOR_DIR"cloth")->wear();

setup();
  }
