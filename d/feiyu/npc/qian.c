#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��Сٻ", ({ "tang xiaoqian" , "tang" , "xiaoqian"}) );
        set("gender", "Ů��" );
        set("age",19 );
        set("long", "��Сٻ���������Ů����������ĸ�׳��ļ�ֱһģһ����\n");
        set("combat_exp", 170);
        set("per", 30);

        setup();

        set("chat_chance", 4);
        set("chat_msg", ({
                "��Сٻ���Ŵ��⣬��֪��������ʲô��������\n",
                "��Сٻ�����������˭�ܰ����ҵ���������ѽ��\n",
        }) );
        carry_object(ARMOR_DIR"cloth")->wear();
}
