#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���ϰ�", ({ "zhou laoban" , "zhou" , "boss"}) );
        set("title",HIR"�ܰ�Ƥ"NOR);
        set("gender", "����" );
        set("age", 40);
        set("long", "���ϰ�����Ц���еء�\n");

        set("combat_exp", 1200);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
