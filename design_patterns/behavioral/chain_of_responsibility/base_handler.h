#ifndef BEHAVIORAL_CHAIN_OF_RESPONSIBILITIES_BASE_HANDLER_H
#define BEHAVIORAL_CHAIN_OF_RESPONSIBILITIES_BASE_HANDLER_H

#include <memory>
#include <string>

enum class HandlerType { kHandler1, kHandler2, kHandler3 };

struct HandlerRequest {
  HandlerType type;
  std::string data;
};

struct HandlerResponse {
  bool handled;
  std::string response_data;
};

class BaseHandler {
public:
  explicit BaseHandler(const std::string &name)
      : next_handler_(nullptr), name_(name) {}

  void SetNextHandler(BaseHandler *next_handler) {
    next_handler_ = next_handler;
  }

  std::string GetName() const { return name_; }

  bool IsEndOfTheChain() const { return next_handler_ == nullptr; }

  virtual HandlerResponse HandleRequest(const HandlerRequest &request) {
    if (next_handler_) {
      return next_handler_->HandleRequest(request);
    } else {
      return HandlerResponse{false, "Not Handled: " + request.data};
    }
  }

private:
  BaseHandler *next_handler_;
  std::string name_;
};

#endif // BEHAVIORAL_CHAIN_OF_RESPONSIBILITIES_BASE_HANDLER_H
