#pragma save_binary
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *ob,*user;
	int i;
	string msg;
	msg="系统清除程序启动……所有人将被移动到天堂。\n";
	message("vision",HIC+msg+NOR,users());

	ob=objects();
	user=users();
	reset_eval_cost();
	
	for(i=0;i<sizeof(user);i++)
	{
		user[i]->move("/d/death/god2");
        reset_eval_cost();
	}

	for(i=0;i<sizeof(ob);i++)
	{
        reset_eval_cost();
		if(ob[i])
		{
		if(userp(ob[i])) continue;
             if(base_name(ob[i])[0..2]!="/d/") continue;
		if(base_name(ob[i])=="/d/death/god2") continue;
		if(environment(ob[i])&&userp(environment(ob[i]))) continue;
		destruct(ob[i]);
		}
	}
	msg="清除完毕。\n";
	message("vision",HIC+msg+NOR,users());
	return 1;
}
