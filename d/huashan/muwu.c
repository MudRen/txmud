// Room: /d/huashan/muwu.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
һ���ª�Ĳݷ���ֻ��һ����ܺ�һ�Ŵ�����������ҵض�
�ż������ƵĹ��顣���ߵĵ�����һ�ѿվ�ƿ����������ɢ����
��Ҳ˵�����ζ������ͷ����һ����(hua)��
LONG
);

        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"zhujian",
]));

	set("item_desc", ([ /* sizeof() == 1 */
	"hua" : WHT"    ������һ����Ů��ϴͷ��һ�ַ��裬һ������ͷ�������Ǵ���\n
    ��������һ��ʫ(shi)��ǰ���������Լ���������ּ��پ���\n"NOR,

	"shi":HIC"    ʮ��ƽ��˪���죬�����˿��꣬\n
    �ε�Ӱֻ���໤��ֻĽԧ�첻Ľ�ɡ�\n"NOR
]));

	setup();
	replace_program(ROOM);
}

