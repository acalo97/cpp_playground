#include <gtest/gtest.h>
#include <string>
// Update the path below to the correct relative or absolute path where
// chain_of_responsibility.h exists
#include "../base_handler.h"

class Handler1 : public BaseHandler {
public:
  Handler1(const std::string &name) : BaseHandler(name) {}
  HandlerResponse HandleRequest(const HandlerRequest &request) override {
    if (request.type == HandlerType::kHandler1) {
      return HandlerResponse{true,
                             "Handled by " + GetName() + ": " + request.data};
    } else {
      return BaseHandler::HandleRequest(request);
    }
  }
};

class Handler2 : public BaseHandler {
public:
  Handler2(const std::string &name) : BaseHandler(name) {}

  HandlerResponse HandleRequest(const HandlerRequest &request) override {
    if (request.type == HandlerType::kHandler2) {
      return HandlerResponse{true,
                             "Handled by " + GetName() + ": " + request.data};
    } else {
      return BaseHandler::HandleRequest(request);
    }
  }
};

class Handler3 : public BaseHandler {
public:
  Handler3(const std::string &name) : BaseHandler(name) {}
  HandlerResponse HandleRequest(const HandlerRequest &request) override {
    if (request.type == HandlerType::kHandler3) {
      return HandlerResponse{true,
                             "Handled by " + GetName() + ": " + request.data};
    } else {
      return BaseHandler::HandleRequest(request);
    }
  }
};

class ChainOfResponsibilityTestFixture : public ::testing::Test {
  void SetUp() override {
    handler1 = new Handler1("Handler1");
    handler2 = new Handler2("Handler2");
    handler3 = new Handler3("Handler3");

    handler1->SetNextHandler(handler2);
    handler2->SetNextHandler(handler3);
  }
  void TearDown() override {
    delete handler1;
    delete handler2;
    delete handler3;
  }

protected:
  BaseHandler *handler1;
  BaseHandler *handler2;
  BaseHandler *handler3;
};

TEST_F(ChainOfResponsibilityTestFixture, CreateAChainAndProcessRequest) {

  EXPECT_EQ(handler3->IsEndOfTheChain(), true);

  const auto result = handler1->HandleRequest(
      HandlerRequest{HandlerType::kHandler1, "Test Data"});

  EXPECT_TRUE(result.handled);

  EXPECT_EQ(result.response_data, "Handled by Handler1: Test Data");
}

TEST_F(ChainOfResponsibilityTestFixture,
       CreateAChainAndProcessUnsupportedRequest) {

  EXPECT_EQ(handler3->IsEndOfTheChain(), true);

  const auto result = handler1->HandleRequest(
      HandlerRequest{static_cast<HandlerType>(42U), "Test Data"});

  EXPECT_FALSE(result.handled);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
