//boy.c ����С�к���
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����С�к�", ({ "boy" }) );
        set("age", 13);
        set("long", "С�к���͵͵������СŮ����\n");
        
        set("str",10);
        set("per",23);
        set("chat_chance",4);
        set("chat_msg", ({
                CYN"С�к�˵��׿�굽��ϲ��ϲ�����أ�\n"NOR,
                CYN"С�к�˵�������ܰ���׽һֻС����\n"NOR,
                }) );
        set("inquiry",([
        "׿��":"׿�����׿�갡��\n",
]));        
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
        setup();
        carry_object(__DIR__"obj/zang-xue")->wear();
        carry_object(__DIR__"obj/zang-xue")->wear();
}
int accept_object(object who,object ob)
{
        if((string)ob->query("id")=="bird" ) {
                say(CYN"С�к�˵���Ҳ�Ҫ�ˣ��������͸�׿�����\n"NOR);
                command("shy");
                return 0;
        }
}

