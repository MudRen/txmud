#include <ansi.h>
inherit NPC;

void create()
{
        set_name("С��", ({ "xiao yi"}) );
        set("nickname",WHT"���軨��"NOR);
        set("title",MAG"��������Ů��"NOR);
        set("gender", "Ů��" );
        set("age", 25);
        set("long", "�����ĳ��棬�����޷����������ݡ�\n");
        set("combat_exp", 10);
        set("per", 30);

        set("chat_chance", 5);
        set("chat_msg", ({
                "С�⾲�����ڴ���һ���˶���˵,˵�����Ǹ��˽���Ψһ�Ĵ�˵...������\n",
                "С���ڵȴ�һ���˶���˵,˵������ֻ�����������˲�֪��...������\n",
        }) );
        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

