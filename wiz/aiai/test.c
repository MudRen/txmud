//С����ϰ��npc
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("С����Baby", ({ "Airun's baby", "baby", "ab" }));
        set("title",HIW"��ϰŮ��"NOR);
        set("age", 20);
        set("gender", "Ů��");

        set("long",
            "������С������ϰ���ѡ�
ÿ��ֻ����һ���������ﾭ����С�����Ͽ�ѵ����\n" );
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
         "airun": "С����Baby��ȻһЦ���������ҵ����ˣ�����������������û��������϶�����PSO����\n",
         "С��": "С����Baby��ȻһЦ���������ҵ����ˣ�����������������û��������϶�����PSO����\n",
         "aiai": "С����Baby��ȻһЦ���������ҵ����ˣ�����������������û��������϶�����PSO����\n",
         "����": "С����Baby��ȻһЦ���������ҵ����ˣ�����������������û��������϶�����PSO����\n",
"����":"С����Ŀǰ�Ĺ����Ǹ���ɽ����������\n",
"�绰����":"С���ĵ绰������13019137374����˵�����ֻ���Ƿ���ˡ�����\n",
          ]));
           setup();
         add_money("gold",4000);
         carry_object(ARMOR_DIR"cloth")->wear();

}

void init()
{
        object ob;

        ::init();
        if( living(ob = previous_object()) && !is_fighting() && !wizardp(ob))
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        string day_night;
        int time;

/*        if( !ob
        || (environment(ob) != environment())
        || file_name(environment()) != this_object()->query("startroom"))
                return;  
*/

        if(!is_day())
        {
                sscanf( day_night(),"%s %d",day_night,time);
                say( (time > 480) ? CYN"��ô����죬С���Ѿ������ˣ�"+RANK_D->query_respect(ob)+
                        "�����������ɡ�\n"NOR
                        : ( (time <= 60) ? CYN"С���õ�ͷ���������Ͼ�Ҫ�����ˣ���λ�͹����һ�°ɡ�\n"NOR
                        : CYN"С����Baby���˸�����˵����С�껹û�п��ţ��������������ɡ�\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"С����BabyЦ�����˵�������ڡ����¡���������wiz��ϣ�����ӻԾ��������\n"NOR);
                        break;
                                case 1:
                        say( CYN"С����BabyЦ�����˵����Ԫ��֮ǰ�ã���ӭ��λ��TX�ոտ��ţ�лл���֧�֡�\n"NOR);
                        break;
                }
        }
}

