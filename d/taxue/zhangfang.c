// zhangfang.c
// by dicky

#include <ansi.h>
inherit BANK;

void create()
{
        set("short", "�ʷ�");
        set("long", @LONG
������ɽׯ���ʷ����ı�ѩ�׵�ǽ���м��и����̨����̨ǰ�Ϸ�����һ
�����ӣ�paizi���� ���Ｗ��������ȡǮ���ɽׯ���ӣ��Ե�ʮ�����ӡ��ʷ�
�����Ǹ���ʮ�������ͷ�����������˽�������Ц������ӭ��������
LONG
        );
        
	set("item_desc",([
		"paizi" :
          "�������ʷ���Ŀǰ�����ṩ�ķ����У�

huan            �һ�Ǯ��
cunqian         ��Ǯ
quqian          ȡǮ
chazhang        ����
zhuan		ת�ˡ�\n",
	]));
 
        set("no_beg", 1);

        set("exits", ([
               "south" : __DIR__"dongting",               
        ]));
        
        set("objects", ([
               __DIR__"npc/guanjia7" : 1,
        ]));

        setup();
}
