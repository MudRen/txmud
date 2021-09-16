// bingqiku.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ɽׯ�ı����⣬��Χ�ı������Ϸ��źܶ��������������ì��ꪵ�
ʮ�˰�����������롣һȺɽׯ������վ�ڼ�ǰ��ѡ�Լ����ֵı��С���һ��
�����Ÿ��ֱ����ı�����(jia)�ڷ������С�
LONG
        );      	 
	
        set("exits", ([
               "north" : __DIR__"donglang2",               
        ]));
        
        set("objects", ([
		__DIR__"npc/dizi5":1,
        ]));

        set("item_desc", ([
                "jia" : "����һ��ר�������Ÿ��ֱ����ļ��ӡ�
�����У�
       ��(blade)��       ��(hammer)��
       ǹ(spear)��       ��(whip)��
       ��(staff)��       ��(sword)��
���������������(na)��ʹ�ã�Ҳ���԰Ѳ�Ҫ�ı�����(fang)�����档
\n"]));
        set("blade_count", 5);            
        set("hammer_count", 5);   
        set("spear_count", 5);      
        set("staff_count", 5);
        set("sword_count", 10);
        set("whip_count", 5);           

        setup(); 
	replace_program(ROOM);
}

void init()
{
        add_action("do_get","na");
        add_action("do_put","fang");
}

int do_get(string arg)
{
       object me,ob;
       string arg1;
       me=this_player();

       if(!arg) return notify_fail("�����ʽ: na <��������> \n");
       switch (arg){
          case "blade": arg1="/obj/weapon/blade"; break;             
          case "hammer": arg1="/obj/weapon/hammer"; break;   
          case "whip": arg1="/obj/weapon/whip"; break;         
          case "spear": arg1="/obj/weapon/spear"; break;
          case "staff": arg1="/obj/weapon/staff"; break;           
          case "sword": arg1="/d/taxue/obj/sword"; break;
          default :
                 return notify_fail("û�����ֱ�����\n");
          }
       if (me->is_busy())
		return notify_fail("����æ���ء�\n");
       if(query(arg+"_count") < 1)
          return notify_fail("���ֱ����Ѿ����ù��ˡ�\n");
       add(arg+"_count", -1);
       ob=new(arg1);
       if(ob) ob->move(me);
       ob->set("value", 10);
       message_vision("$N�ӱ��������ó�һ"+ob->query("unit")+"$n��\n",me, ob);  
       return 1;
}
int do_put(string arg)
{
       object me, ob;
       string arg1;
       me=this_player();
       if (!arg) return 0;
       if (me->is_busy()) return notify_fail("����æ���ء�\n");
       if( !objectp(ob = present(arg, me)) )
         return notify_fail("������û������������\n");
       if(!ob->query("weapon_prop")) 
         return notify_fail("��ֻ�ܽ��������ڱ������ϡ�\n");
       if (me->is_busy())
		return notify_fail("����æ���ء�\n");

       arg1=ob->query("skill_type");
       switch (arg1){
          case "blade": add("blade_count", 1); break;             
          case "hammer": add("hammer_count", 1); break;   
          case "whip": add("whip_count", 1); break;         
          case "spear": add("spear_count", 1); break;
          case "staff": add("staff_count", 1); break;
          case "sword": add("sword_count", 1); break;           
          default :
                 return notify_fail("�㲻�ܽ����ֱ������ڱ������ϡ�\n");
          }
       message_vision("$N�ó�һ"+ob->query("unit")+"$n���ڱ������ϡ�\n",me, ob);  
       destruct(ob);
       return 1;
}

