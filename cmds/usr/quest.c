// quest.c
// by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string clas;
	mapping quest;

	if(mapp(quest = me->query("enyi_class")) && sizeof(quest))
	{
		if( !quest["finish"] || (quest["finish"] != quest["id"]) )
		{
			write(sprintf("你目前已接受了《仁义山庄》的委托去追杀%s(%s)的任务。\n",
				quest["name"], quest["id"]));
			return 1;
		}
		else
			return notify_fail(sprintf("你已经完成了《仁义山庄》委托你追杀%s的重任，快去交差吧。\n", quest["name"]));
	}


	if(!(clas = me->query("class"))
	|| !mapp(quest = me->query(sprintf("quest/%s_quest",clas))) )
		return notify_fail("\n你现在没有需要去做的任务。\n\n");

	write(sprintf("\n你目前的任务是去%s『%s』。\n%s\n\n",
		quest["quest"],quest["name"],
		!undefinedp(quest["hint"])?sprintf("提示：%s",quest["hint"]):"" ));

	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quest
 
这个指令可以显示出你当前的任务。
HELP
        );
        return 1;
}
