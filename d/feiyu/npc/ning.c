#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�����", ({ "ningyu er","er","ningyu"}) );
        set("title",WHT"С�Թ�"NOR);
        set("gender", "Ů��" );
        set("age", 18);
        set("long", "������Ц�����ģ�һ���������ǵ����ӡ�\n");
        set("combat_exp", 500);
        set("per", 30);
        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
