//girl.c ����СŮ����
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����СŮ��", ({ "girl" }) );
        set("age", 12);
        set("long", "СŮ������Ī�������һ����Ρ�\n");
        
        set("str",10);
        set("per",26);
        set("inquiry",([
        "׿��":"�Ҿ���׿�꣬��ʲô����",
]));        
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/zang-xue")->wear();
}
int accept_object(object who,object ob)
{
        if((string)ob->query("id")=="bird" ) {
                say(
CYN"СŮ��˵�����ʴ����ҵ�������档\n"NOR
CYN"СŮ��˵����˵�嶫�Ǹ�ɭ���и��򵥵ķ�������ʥ����\n"NOR
CYN"СŮ��˵���ţ������Ǹ��Ǹ��쵰��ʦ�е��ϵ��\n"NOR
);
                command("giggle girl");
                destruct(ob);
                return 1;
        }
}

